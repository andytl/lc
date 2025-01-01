
## For VSCode
- Notes from https://code.visualstudio.com/docs/cpp/config-msvc
- Install Microsoft Visual C++ (MSVC) compiler toolset
- Launch VSCode from the VSDevCmd environment
- Install CMake extension
- Open this project

### Adding a new file
- Re-run `CMake: Configure` when adding new files.

### Running and debugging
- To Run: `CMake: Run Without Debugging` (default shortcut: Ctrl+F5)
- To Debug: Place breakpoints using VSCode.
  - `CMake: Debug`
  - To set breakpoints, you might need to set `"editor.glyphMargin": true`

### About launch.json
- Notes on configuring F5 for CMake: https://github.com/microsoft/vscode-cmake-tools/blob/main/docs/debug-launch.md
- Without the external console flag, look at the "Debug Console" for the program output.
- Two optional launch configurations are provided in the repo for quick debugging with F5.

## For command line use
```
# One Time bootstrap
mkdir bin
cd bin
cmake ..

# Build and run tests
cmake --build .
# Windows Specific...
.\Debug\LC.exe --gtest_filter=topKFrequent*
```