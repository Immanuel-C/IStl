workspace "IStl"
    configurations {"Debug", "Release"}
    architecture "x86_64"

    function defaultBuildCfg()
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"
            runtime "Debug"
            optimize "Debug"

        filter "configurations:Release"
            defines { "NDEBUG" }
            symbols "Off"
            runtime "Release"
            optimize "Speed"
    end

    function defaultBuildLocation()
        targetdir ("bin/%{prj.name}/%{cfg.buildcfg}")
        objdir ("bin-int/%{prj.name}/%{cfg.buildcfg}")
    end

    startproject "Test"

    project "Test"
        location "test"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"

        files {
            "%{prj.location}/**.cpp",
            "%{prj.location}/**.h",
        }

        includedirs { "src" }

        defaultBuildLocation()
        defaultBuildCfg()

    project "IStl"
        location "src"
        kind "StaticLib"
        language "C++"
        cppdialect "C++20"

        -- Should define all of these preprocessor defines in client apps too.

        defines { 
            "ISTL_CXX20=20",
            "ISTL_CXX17=17",
            "ISTL_CXX14=14",
            "ISTL_CXX11=11",
            "ISTL_CXX_VERSION=ISTL_CXX20",
        }


        files {
            "%{prj.location}/**.cpp",
            "%{prj.location}/**.hpp",
        }

        defaultBuildLocation()
        defaultBuildCfg()