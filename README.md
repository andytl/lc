

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