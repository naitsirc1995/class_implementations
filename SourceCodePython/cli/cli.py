import argparse
from cli.cli_handler import handler, country_handler

def parseArguments():
    parser = argparse.ArgumentParser()
    parser.add_argument("-e","--example",required=False)
    parser.add_argument("-c","--country",required=False)
    args = parser.parse_args()
    example = args.example
    country = args.country
    if example is not None:
        handler(example=example)
    elif country is not None:
        country_handler(country=country)
    else:
        print("[error] argument passed is not correct")    