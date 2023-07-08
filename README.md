# Cpp-Tanja84dk-Crypt

## 1. Introduction

This is mostly a wrapper collections of encodings/chiphers that I use in some of my things to make it easier if I have to change out the actual encoding/chipher that i need

### 1.1 Background

The reason I made it in to a collection instead of seperate were I saw myself need it several times so it made it alot easier to maintain to have it as its own module/project that I then only have to update one place

### 1.2 Working at this moment

## 2. Technical

### 2.1 Required libraries

- CPM - CMake dependency management 0.38.1
- cryptopp-cmake - CMake Project for Crypto++ 8.8.0
- cryptopp - Crypto++ Library 8.8.0

### 2.2 Requiring libraries

CMake dependency management is used to download the required libraries for compiling so its not needed for you to have it installed on your system prior compiling

By default its downloading the libraries to the build folder and is storing them within a folder called \_deps

About Crypto++ that is pulled from within the cryptopp-cmake project since Crypto++ does not distribute as a cmake project and the Crypto++ maintainer is also endorcing and forwarding to the cryptopp-cmake repo as the official for cmake projects [Wiki CMake Page](https://www.cryptopp.com/wiki/CMake#:~:text=using%20Android%20options-,Downloads,-cryptopp%2Dcmake%20%2D%20GitHub)

## 3. Licenses

- CPM is licensed under MIT [CPM 0.38.1 License](https://github.com/cpm-cmake/CPM.cmake/blob/v0.38.1/LICENSE)
- cryptopp-cmake is licensed under BSD 3-Clause License [cryptopp-cmake 8.8.0 License](https://github.com/abdes/cryptopp-cmake/blob/CRYPTOPP_8_8_0/LICENSE)
- Crypto++ Library is licensed under Boost Software License - Version 1.0[Crypto++ 8.8.0 License](https://github.com/weidai11/cryptopp/blob/CRYPTOPP_8_8_0/License.txt)

## 4. Credit

- CPM for the depentencies manager [Github](https://github.com/cpm-cmake/CPM.cmake)
- abdes for the cmake project for Crypto++ Library[Github](https://github.com/abdes/cryptopp-cmake)
- Crypto++ and the comunity for the Crypto++ Library collection[Github](https://github.com/weidai11/cryptopp)
