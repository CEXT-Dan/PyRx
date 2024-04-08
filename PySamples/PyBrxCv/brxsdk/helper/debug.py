import os 

# debug
def pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()
    # print("\nLaunching debugpy..")

# https://stackoverflow.com/questions/9727673/list-directory-tree-structure-in-python
def fs_tree_to_dict(path_):
    file_token = ''
    for root, dirs, files in os.walk(path_):
        tree = {d: fs_tree_to_dict(os.path.join(root, d)) for d in dirs}
#        tree.update({f: os.path.getsize(os.path.join(root, f)) for f in files})
        tree.update({f: calculate_file_hash(os.path.join(root, f)) for f in files})
#        tree.update({f: file_token for f in files})
        return tree

# https://www.geeksforgeeks.org/how-to-detect-file-changes-using-python/
import hashlib
import time
def calculate_file_hash(file_path):
    with open(file_path, "rb") as f:
        file_hash = hashlib.sha256(f.read()).hexdigest()
    return file_hash

def detect_file_changes(file_path):
    last_hash = fs_tree_to_dict(file_path)
    while True:
        current_hash = fs_tree_to_dict(file_path)
        if current_hash != last_hash:
            print("Something has changed, reloading modules!")
#            reload_modules()
            last_hash = current_hash
        time.sleep(1)

# https://stackoverflow.com/questions/4858100/how-to-list-imported-modules
import sys
import importlib
def reload_modules():
    # modulenames = set(sys.modules) & set(globals())
    # allmodules = [sys.modules[name] for name in modulenames]
    # for i in allmodules: 
#        importlib.reload(i)
#        print(' {}'.format(i)) 
    for key in sys.modules.keys():
#        print(key.split('.', 1))
#        if key.split('.', 1)[0] == "pybrxcv":
        if key[:8] == "pybrxcv.":
            print(' {}'.format(key[:8]))
#            importlib.reload(key)


#fs_tree = fs_tree_to_dict('C:/Users/Sebastian Schoeller/Documents/GitHub/PyBrxCv/pybrxcv')
#print(fs_tree)

# from pathlib import Path

# def files_tree(startpath):
#     for p in Path( '.' ).rglob( '*.py' ):
#         print( p )

# print(files_tree('C:/Users/Sebastian Schoeller/Documents/GitHub/PyBrxCv/pybrxcv'))

# # https://stackoverflow.com/questions/9727673/list-directory-tree-structure-in-python
# def list_files(startpath):
#     for path, dirs, files in os.walk(startpath):
#         print(path)
#         for f in files:
#             print(f)

#print(list_files('C:/Users/Sebastian Schoeller/Documents/GitHub/PyBrxCv/pybrxcv'))

# # https://stackoverflow.com/questions/43752962/how-to-iterate-through-a-nested-dict#43753252
# def print_all(df):
#  #iterates through a nested dict and prints all values
#  for key in df.keys():
#          if type(df[key]) == dict:
#                  print_all(df[key])
                 
#          else:
#                print(key,':',df[key])

#print_all(fs_tree)
#print(list_files('C:/Users/Sebastian Schoeller/Documents/GitHub/PyBrxCv/pybrxcv'))

# for key, value in fs_tree.items():
#     print(value)
#    print(value)