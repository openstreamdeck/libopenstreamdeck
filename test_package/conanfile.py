import os
from conans import ConanFile, CMake, tools

class LibOpenStreamDeckTestConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "cmake_find_package"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def requirements(self):
        self.requires("boost/1.78.0")
        self.requires("libopenstreamdeck/0.1.0")

#    def test(self):
#        if not tools.cross_building(self):
#            self.run(".%sexample" % os.sep)
