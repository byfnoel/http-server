# HTTP-SERVER

High-performance HTTP server written in C++

## HTTP-Connection-journey
![Http-Connection-Design]
(https://user-images.githubusercontent.com/63328653/155897372-ced93b84-9037-4fee-9970-f5bc9dc5573a.png)

## Usage

Clone the repository:
```
git clone git@github.com:byfnoel/http-server
```

and
```
cd http-server
```

run
```
g++ -std=c++17 -I/Users/francisconoel/Workspace/http-server/build/asio/asio/include  src/main.cpp -lpthread
```

then
```
./a.out
```

## License

Licensed under either of

 * Apache License, Version 2.0
   ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
 * MIT license
   ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)

at your option.
