# Information
## Purpose
<p>Simple to use, non intrusive library to serialize and deserialize structures and classes</p>
<p>How to use: build the source<br>
Copy the <code>Library</code> folder, it should contain <code>parser.h</code>, 
<code>serialize.h</code> and copy everything in <code>generated</code> folder including the folder</p>

## Limitations
<p>Can be used for structures containing: <code>primitives, std::string</code></p>

# How to build

## Linking:
<p> You need to include: </p>
* <code>LLVM/include</code><br>
* <code>LLVM/lib</code><br>
<p> Library files: </p>
* <code>libclang.lib</code>

<p>Running the executable:<br>Format is: 
<code>-I "lib header path" <"files"></code>
</p>