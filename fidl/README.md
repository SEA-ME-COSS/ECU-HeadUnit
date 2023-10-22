# fidl and fdepl

Franca IDL is utilized for CommonAPI. In '.fidl' file, interfaces for inter-process communication are defined, along with the methods that will be executed within those interfaces. '.fdepl' files assign unique IDs to objects defined in the .fidl file.

These two files exist for the purpose of code generation and are not required during the compilation phase managed by CMake. Code generation is accomplished through the core-generator and someip-generator, and you can learn more about installing these generators through the instructions provided in the "settings" folder. The following is the command for generating the code.

```bash
cd ..
~/generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/DESProject.fidl -d ./src-gen-desproject
~/generator/someip-generator/commonapi-someip-generator-linux-x86_64 ./fidl/DESProject.fdepl -d ./src-gen-desproject
```

This command creates a folder named "src-gen-desproject" and saves the generated code inside it.
