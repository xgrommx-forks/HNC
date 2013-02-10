# Quick Start

## Windows

Install Haskell Platform then run:
```
cabal update
cabal install --only-dependencies
configure
build
dist\build\spl-hnc\spl-hnc hn_tests\euler6.hn
```

## *nix

Install GHC or Haskell Platform and run:

```
cabal update
cabal install --only-dependencies
PATH=$PATH:~/.cabal/bin
cabal configure
cabal build
./dist/build/spl-hnc/spl-hnc ./hn_tests/euler6.hn
```

# Advanced use

- read wiki
- run our test suites
- run `hnc` with `-O` option to see our first attempts at optimization
- feed generated `.cpp` files to a C++ compiler and linker either directly or by using our extension to Boost.Build.

You'll need MSVC/GCC, Boost and Boost.

# Under the hood

HNC is an open-source cross-platform compiler based on modern technologies: Glasgow Haskell Platform, 
UUAGC attribute grammar preprocessor, Parsec parsing library, HOOPL graph optimization library. 
The codebase is tiny: less than 4 KLOC, in the spirit of VPRI Ometa.

## State of affairs

Many HN programs can already be compiled into an ugly functional subset of C++ and 
then into executables and run (see `hn_tests` folder for `.hn` sources and `.cpp` targets). 
A UDP echo server and a few Project Euler problems are the only useful programs so far, 
but mostly because we are too lazy to write more examples.

## What is done

- Parser
- Type inference using UUAG, including injection of explicit template parameters when C++ doesn't infer them
- Identifier- and scope-preserving translation from AST into graph IR and back using HOOPL dominator analysis
- A rudimentary and buggy optimizer of the IR using HOOPL
- Compiler of closures into C++ functors using UUAG (almost)
- C++ pretty printer (almost)
- A Boost.Build plugin to integrate .hn files into C++ projects

## What is not done

- Proper error reporting
- Loops and assignments
- The inliner is buggy for HOFs
- The instantiator of polymorphic code into monomorphic is not implemented
- Module system, namespace support, HNI implementation and C++ integration in general are rudimentary or missing
- Priorities of C++ infix operators are broken
- RAII should be used with care
- Our Boost-based implementation of a generalization of <code>std::bind1st</code> only works under MSVC
- SPL support is almost missing
- Polymorphic constants like “empty list” are not supported

## License

Distributed under GNU Lesser General Public Licence Version 3.
