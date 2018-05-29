cmake_minimum_required(VERSION 3.10)
project(usb_pd C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_library(usb-pd SHARED libusb-pd.c libusb-pd.h)

install(TARGETS usb-pd DESTINATION lib)
install(FILES libusb-pd.h DESTINATION include)

include_directories(/usr/include)
link_directories(/usr/lib)
#
add_executable(crc32 crc32.c libusb-pd.c libusb-pd.h)