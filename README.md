# Torrent
A simple cli torrent downloader built using libtorrent

## Installation

*Instructions are given for MacOS*

---
Install libtorrent
```shell
brew install libtorrent-rasterbar
```

Download the `torrent.cpp` and compile using libtorrent
```shell
wget https://raw.githubusercontent.com/tomginsberg/torrent/main/torrent.cpp
g++ -std=c++14 -I/opt/homebrew/include -L/opt/homebrew/lib -o torrent torrent.cpp -ltorrent-rasterbar -lboost_system
chmod +x torrent
```

## Usage
```shell
torrent "paste your magnet link"

## prints lives updates of download progress
Downloading...
55.148% complete (down: 218 kB/s up: 876 kB/s peers: 5)
```
