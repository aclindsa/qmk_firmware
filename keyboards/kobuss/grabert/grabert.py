#!/usr/bin/env python

"""
This script can be used to send a message to be displayed on the OLED of a
Grabert keyboard. Example usage:

$ ./grabert.py message --flash 'Hello, world!\n'
$ ./grabert.py message --append "Bye now..."
"""

import argparse
from enum import IntEnum
import hid # https://github.com/trezor/cython-hidapi, `pacman -S python-hidapi` on Arch
import sys
import time

GRABERT_VID = 0x1209
GRABERT_PID = 0xBA01
RAW_USAGE_PAGE = 0xFF60
RAW_USAGE = 0x61

# Must be synced to grabert.h
class Command(IntEnum):
    ID_SET_MESSAGE_TIMEOUT = 0xB0
    ID_SET_INVERT_TEXT     = 0xB1
    ID_START_MESSAGE       = 0xB2
    ID_APPEND_MESSAGE      = 0xB3

def find_path(vid, pid, usage_page, usage):
    for d in hid.enumerate():
        if d['vendor_id'] == vid and \
                d['product_id'] == pid and \
                d['usage_page'] == usage_page and \
                d['usage'] == usage:
            return d['path']
    return None

def get_device():
    h = hid.device()
    path = find_path(GRABERT_VID, GRABERT_PID, RAW_USAGE_PAGE, RAW_USAGE)
    if not path:
        print("Error: Failed to find device")
        sys.exit(1)
    h.open_path(path)

    return h

def send_payload(payload):
    """Send a payload, padding it if necessary"""
    assert(len(payload) <= 32)
    payload = payload + [0] * (32 - len(payload))

    h = get_device()
    h.set_nonblocking(1)
    h.write(payload)

def set_timeout(timeout):
    """Set how long a message will be displayed, in seconds"""
    send_payload([Command.ID_SET_MESSAGE_TIMEOUT, timeout])

def set_invert(invert=True):
    """Set how long a message will be displayed, in seconds"""
    send_payload([Command.ID_SET_INVERT_TEXT, 0x1 if invert else 0x0])

def write_message(s, append=False):
    """Send message to be written to keyboard OLED"""
    for c in s:
        if ord(c) > 255:
            print(f'Error: ASCII code of character \'{c}\' is above 255, unable to send\n')
            sys.exit(1)

    chunks = [s[y-30:y] for y in range(30, len(s) + 30, 30)]
    for chunk in chunks:
        payload = [Command.ID_APPEND_MESSAGE if append else Command.ID_START_MESSAGE] + [ord(c) for c in chunk]
        append = True
        send_payload(payload)

def main():
    parser = argparse.ArgumentParser(description='Send message for display on Grabert OLED')
    subparsers = parser.add_subparsers(dest='subcommand')

    message_parser = subparsers.add_parser('message')
    message_parser.add_argument('--timeout', type=int, default=10,
                        help='Time to display message for (in seconds)')
    message_parser.add_argument('--flash', action='store_true',
                        help="Flash message in inverted colors for one second (note, will delay script return by one second)")
    message_parser.add_argument('--append', action='store_true',
                        help="Append to currently-displayed message, if any")
    message_parser.add_argument('text', type=str,
                        help="Message text to display on OLED (ASCII onlyto screen)")

    args = parser.parse_args()

    if args.subcommand == 'message':
        set_invert(args.flash)
        set_timeout(args.timeout)
        message = args.text.replace("\\n", "\n")
        write_message(message, append=args.append)
        if args.flash:
            time.sleep(1)
            set_invert(False)

if __name__ == "__main__":
    main()
