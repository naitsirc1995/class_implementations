import argparse
from cli.cli_handler import handler

def parseArguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-e","--example",required=True)
    args = parser.parse_args()
    handler(example=args.example)
    