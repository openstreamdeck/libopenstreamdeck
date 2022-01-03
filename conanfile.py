from conans import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake
from conan.tools.layout import cmake_layout

class LibOpenStreamDeckConan(ConanFile):
    name = "libopenstreamdeck"
    version = "0.1.0"
    license = "LGPL-2.1 License"
    author = "Cyril Vlaminck cyril.vlaminck@gmail.com"
    url = "https://github.com/openstreamdeck/libopenstreamdeck"
    description = "An open-source C++ 20 library to write plugin for the Stream Deck on Windows/Mac."
    topics = ("stream deck")
    generators = "CMakeToolchain"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "conanbuildinfo.cmake", "openstreamdeck/**"

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["openstreamdeck"]
