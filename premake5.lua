workspace "Joto"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
    project "Joto"
        location "Joto"
        kind "SharedLib"
        language "C++"

        targetdir ("bin/"..outputdir.."/%{prj.name}")
        objdir ("bin-int/"..outputdir.."/%{prj.name}")


        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "%{prj.name}/vendor/spdlog/include",
            "%{prj.name}/src"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "10.0.17134.0"

            defines
            {
                "JT_PLATFORM_WINDOWS",
                "JT_BUILD_DLL"
            }

            postbuildcommands
            {
                ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
            }

        filter "configurations:Debug"
            defines "JT_DEBUG"
            symbols "On"
        filter "configurations:Release"
            defines "JT_RELEASE"
            optimize "On"
        filter "configurations:Dist"
            defines "JT_DIST" 
            optimize "On"
    project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/"..outputdir.."/%{prj.name}")
        objdir ("bin-int/"..outputdir.."/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "Joto/vendor/spdlog/include",
            "Joto/src"
        }

        links
        {
            "Joto"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "10.0.17134.0"

            defines
            {
                "JT_PLATFORM_WINDOWS"
            }

        filter "configurations:Debug"
            defines "JT_DEBUG"
            symbols "On"
        filter "configurations:Release"
            defines "JT_RELEASE"
            optimize "On"
        filter "configurations:Dist"
            defines "JT_DIST" 
            optimize "On"
