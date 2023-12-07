# fidl and fdepl

Franca IDL is utilized for CommonAPI. In '.fidl' file, interfaces for inter-process communication are defined, along with the methods that will be executed within those interfaces. '.fdepl' files assign unique IDs to objects defined in the .fidl file.

These two files exist for the purpose of code generation and are not required during the compilation phase managed by CMake. Code generation is accomplished through the core-generator and someip-generator, and you can learn more about installing these generators through the instructions provided in the [setting](../setting/) folder.

Running the 'src_gen_cmd' script in the main directory will create a folder named 'src-gen' and save the generated code inside it.

```bash
sh src_gen_cmd.sh
```
