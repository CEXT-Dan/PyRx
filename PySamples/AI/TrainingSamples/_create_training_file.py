import time
import random
import sys
import hashlib

def create_training_file():
    # Create a unique 7-character hex hash (like a Git commit)
    seed = f"{time.time()}{random.random()}"
    short_id = hashlib.sha256(seed.encode()).hexdigest()[:7]
    
    filename = f"pyrx_{short_id}.py"
    
    # Use the same short_id for the function name to keep them linked
    content = f"""from pyrx import Ap, Db, Ed, Ge, command

@command
def pycmd_{short_id}():
    db = Db.curDb()
"""
    with open(filename, "w") as f:
        f.write(content)
    return filename

if __name__ == "__main__":
    count = int(sys.argv[1]) if len(sys.argv) > 1 else 10
    for _ in range(count):
        print(f"Created: {create_training_file()}")
