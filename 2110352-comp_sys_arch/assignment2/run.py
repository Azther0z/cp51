import subprocess
import os

def run_c_program(exe_path, arguments=None):
    # Ensure the file actually exists
    if not os.path.exists(exe_path):
        print(f"Error: The file '{exe_path}' was not found.")
        return

    try:
        # Construct the command
        command = [exe_path]
        if arguments:
            command.extend(arguments)

        # Run the program
        # capture_output=True grabs stdout and stderr
        # text=True treats the output as a string instead of bytes
        result = subprocess.run(command, capture_output=True, text=True, check=True)

        print("--- Program Output ---")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        print(f"Program failed with exit code {e.returncode}")
        print(f"Error Message: {e.stderr}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    # Replace with the actual name or path of your compiled C file
    path_to_exe = "./main.exe" 
    
    # Optional: list of command-line arguments to pass to the C program
    
    for cache in [4,8,16,32]:
        for block in [4,8,16,32]:
            run_c_program(path_to_exe, ['gcc_ld_trace.txt',f'{cache}',f'{block}','1','RR'])
    
    for algo in ['LRU','RR']:
        for way in [2,4]:
            for cache in [1,4,8,32,512,1024]:
                run_c_program(path_to_exe, ['go_ld_trace.txt',f'{cache}','4',f'{way}',algo])
