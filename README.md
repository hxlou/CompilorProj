## Head
This is used for our compilor project, and welcome to talk.

## Build

The Lab1's file is in `./lab1/src`
The Lab2's file is in `./lab2/src`
The Lab3's file is in `./lab3/src`

```bash
$ cd lab\*
$ rm -rf build
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./compilor
```

## lab3
This part we translate the AST to IR code, use the tool of IR, in `./lab3/accsys/`.

There is a tool to execute the IR, like `test.acc`, in the dir `target/debug/accipit`

```bash
$ ./target/debug/accipit ./tests/IR/test.acc
```