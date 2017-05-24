# encoding: UTF-8

"""
Creates .cabal & Setup.hs to build all the FP solutions
"""

import os
import six


HEADER = """name:                functional-programming
version:             0.1.0.0
synopsis:            domains/functional-programming
homepage:            https://github.com/oopsno/HackerRank/tree/master/domains/functional-programming
license:             GPL-3
author:              YufeiLiu
maintainer:          yufeiliu94@gmail.com
build-type:          Simple
cabal-version:       >=1.10
"""


TEMPLATE = """
executable {}{}
  main-is:             {}/{}
  build-depends:       base >=4.9 && <4.10
  default-language:    Haskell2010
"""


SETUP = """module Main where

import Distribution.Simple

main :: IO ()
main = defaultMain
"""


def parse(filename):
    r"""
    split (\d)+-([A-Za-z]+)\.hs
    """
    if six.PY2:
        serial, name = filename.split('-', 1)
    else:
        serial, name = filename.split('-', maxsplit=1)
    return int(serial), name.split('.')[0], filename


def main():
    """
    create Cabal stuff
    """
    here = os.path.dirname(__file__)
    with open(os.path.join(here, 'Setup.hs'), 'w') as setup:
        setup.write(SETUP)
    with open(os.path.join(here, 'functional-programming.cabal'), 'w') as cabal:
        cabal.write(HEADER)
    subdomains = [('introduction', 'Introduction'),
                  ('recursion', 'Recursion')]
    for subdir, prefix in subdomains:
        files = [parse(e) for e in os.listdir(os.path.join(here, subdir)) if e.endswith('.hs')]
        files.sort(key=lambda x: x[0])
        for _, name, file in files:
            with open(os.path.join(here, 'functional-programming.cabal'), 'a') as cabal:
                cabal.write(TEMPLATE.format(prefix, name, subdir, file))


if __name__ == '__main__':
    main()
