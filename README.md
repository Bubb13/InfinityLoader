# Infinity Loader

<b class="Bold">Please note: This repository is NOT intended to be used for installing EEex; the correct InfinityLoader version is bundled with EEex and will be automatically installed by setup-EEex.exe.</b>

Infinity Loader is utilized by [EEex](https://github.com/Bubb13/EEex) since [version v0.9.0-alpha](https://github.com/Bubb13/EEex/releases/tag/v0.9.0-alpha). Infinity Loader is responsible for starting the game executable, injecting the necessary DLLs, performing any pre-launch patching, and supplying Lua Bindings to support EEex functionality.

## Required compiler tools for InfinityLoader x64

**This is a native Windows C/C++ project built with MSBuild, not CMake or .NET**. You can compile it entirely from the command line without installing the Visual Studio IDE.

1. Run the following in **PowerShell as Administrator**.

   ```pwsh
   $components = @(
       'Microsoft.VisualStudio.Workload.VCTools'
       'Microsoft.VisualStudio.Component.VC.Tools.x86.x64'
       'Microsoft.VisualStudio.Component.Windows11SDK.26100'
       'Microsoft.VisualStudio.Component.VC.Llvm.Clang'
       'Microsoft.VisualStudio.Component.VC.Llvm.ClangToolset'
   )

   $arguments = '--passive --wait --norestart ' +
       (($components | ForEach-Object { "--add $_" }) -join ' ')

   winget install --id Microsoft.VisualStudio.BuildTools `
       --exact --source winget `
       --accept-package-agreements `
       --accept-source-agreements `
       --override $arguments
   ```

   This installs the stable Visual Studio 2026 Build Tools and explicitly selects the required components rather than installing every optional C++ development    tool.

   The `x86.x64` component name is Microsoft's standard package identifier; **it does not mean you must build the x86 version**. You will select x64 when invoking    MSBuild.

   For optional code generation:

   ```pwsh
   # Python (optional, for regenerating bindings)
   winget install --id Python.Python.3.13 --exact --source winget
   ```

2. Legacy DirectX SDK exception

   Some EEex and LuaBindings projects reference:

   ```text
   C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include
   ```

   The binding-generation input also references `d3dx9.h`, which is not part of the modern Windows SDK.

   - **Not fully installable through a verified official WinGet package**.
       - If compilation or regeneration requires the legacy D3DX headers, obtain the SDK directly from [Microsoft DirectX SDK (June 2010)](https://www.microsoft.com/en-us/download/details.aspx?id=6812).
       - Do not confuse the DirectX SDK with the DirectX End-User Runtime. The runtime does not provide development headers.

3. Compile the x64 version

   Open a new **Command Prompt** (`cmd.exe`) after installation.

   Initialize the compiler environment:

   ```batch
   call "C:\Program Files (x86)\Microsoft Visual Studio\18\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
   ```

   That is the standard Visual Studio 2026 Build Tools location; adjust it if you selected a custom installation directory.

   Verify the tools:

   ```batch
   where msbuild
   where cl
   where clang-cl
   where ml64

   msbuild -version
   cl
   clang-cl --version
   ```

   Clone and compile:

   ```batch
   git clone https://github.com/Bubb13/InfinityLoader.git
   cd InfinityLoader

   msbuild InfinityLoader.sln /t:Build /p:Configuration=Release /p:Platform=x64 /m
   ```

   The solution defines `Release|x64`, so there is no need to compile the Win32 configuration.

   The main executable should appear at:

   ```text
   InfinityLoader\x64\Release\InfinityLoader.exe
   ```

   The other DLLs and libraries are written into the corresponding x64 release directories.

4. Build LuaJIT x64 separately (optional)

   The repository has its own `LuaJIT/BUILD_x64.bat`, but that script hardcodes a **Visual Studio 2022 Community** path.

   Either modify this script to point to your `vcvars64.bat`, or instead, after running the Visual Studio 2026 `vcvars64.bat`, invoke the bundled LuaJIT build    script directly:

   ```batch
   cd LuaJIT\src
   call msvcbuild.bat
   ```

   This builds the LuaJIT runtime using the initialized x64 MSVC toolchain. The generated `lua51.dll` is needed if you want to exercise the LuaJIT-based provider.
