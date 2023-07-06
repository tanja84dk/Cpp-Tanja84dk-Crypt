# Cpp-Tanja84dk-Crypt

## 1. Introduction

This is mostly a wrapper collections of encodings/chiphers that I use in some of my things to make it easier if I have to change out the actual encoding/chipher that i need

### 1.1 Background

The reason I made it in to a collection instead of seperate were I saw myself need it several times so it made it alot easier to maintain to have it as its own module/project that I then only have to update one place

### 1.2 Working at this moment

## 2. Technical

### 2.1 Required libraries

- CPM - CMake dependency management 0.38.1
- cpp-base64 by ReneNyffenegger

### 2.2 Requiring libraries

CMake dependency management is used to download the required libraries for compiling so its not needed for you to have it installed on your system prior compiling

By default its downloading the libraries to the build folder and is storing them within a folder called \_deps

About cpp-base64 that has a costum configuration in Findcpp-base64.cmake to setup the library for cmake since its not developed as a cmake project. And its configured to use it as a static library since the permissive license.

## 3. Licenses

- CPM is licensed under MIT [CPM 0.38.1 License](https://github.com/cpm-cmake/CPM.cmake/blob/v0.38.1/LICENSE)
- cpp-base64 by ReneNyffenegger looks like a costum permissive license [cpp-base64 by ReneNyffenegger License](https://github.com/ReneNyffenegger/cpp-base64/blob/82147d6d89636217b870f54ec07ddd3e544d5f69/LICENSE)

## 4. Credit

- CPM for the depentencies manager [Github](https://github.com/cpm-cmake/CPM.cmake)
- cpp-base64 from ReneNyffenegger for the base64 library [Github](https://github.com/ReneNyffenegger/cpp-base64/) [Website/Docs](https://renenyffenegger.ch/notes/development/Base64/Encoding-and-decoding-base-64-with-cpp/)
