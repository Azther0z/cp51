import subprocess
import os

# 1. Compile the C++ code with O3 optimization
print("Compiling C++ code...")
compile_process = subprocess.run(["g++", "-O3", "-o", "solver", "./solver/astar.cpp"])

if compile_process.returncode != 0:
    print("Compilation failed! Please check your C++ code.")
    exit(1)

print("Compilation successful. Running tests...")

# 2. Loop through test cases 1 to 6
for i in range(1, 7):
    in_file = f"{i}.in"
    out_file = f"{i}.out"
    
    if not os.path.exists(in_file):
        print(f"Skipping {in_file} (File not found)")
        continue
        
    print(f"Running test {i}...")
    
    # 3. Read from .in and write to .out
    with open(in_file, "r") as infile, open(out_file, "w") as outfile:
        # On Windows, you might need to use "solver.exe" instead of "./solver"
        executable = "./solver" if os.name != 'nt' else "solver.exe"
        subprocess.run([executable], stdin=infile, stdout=outfile)

    with open(f"{i}-submit.cpp", "w") as submit, open(out_file, "r") as outfile:
        print(len(outfile.readline().strip()))
        submit.write("#include <iostream>\nint main(){"+f'printf("{outfile.readline().strip()}");'+'}')
        
print("All done! Check your .out files.")