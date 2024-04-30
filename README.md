# cpp_weather
This project presents a small example describing how to make api calls using libcurl, the example is nearly completely based on [this curl example](https://gist.github.com/alghanmi/c5d7b761b2c9ab199157). An example for parsing json formatted responses is also provided using [nlohmann/json](https://github.com/nlohmann/json). Example api calls are made to [chubin/wttr.in](https://github.com/chubin/wttr.in).

## Dependencies needed to build the project
- The newest version of [clang](https://clang.llvm.org/) or [gcc](https://gcc.gnu.org/) is recommended.
  - The project should compile as long as your compiler supports c++11.  
- [cmake](https://cmake.org/) > 3.6
- [libcurl](https://github.com/curl/curl)

*You will have to figure out how to install those dependencies for your specific system!*

## Build and run the project
This example applies on Mac-os and Linux. 
I do not know how one would build and run this project using Windows. I do suggest to [RTFM](https://en.wikipedia.org/wiki/RTFM) if you do not know either, and want to run the project on Windows. 

To build project run: 

```
mkdir build
cd build
cmake ..
make
```

The binary "cppWeather" should be found in the ./build directory. 
To run the project: 

```
./cppWeather
```


