import random
import datetime
import os
import shutil

garbage_symbol = "garbage"
specific_device_name = "device_"

alphabet = [
    "A", "a", 
    "B", "b", 
    "C", "c", 
    "D", "d", 
    "E", "e", 
    "F", "f", 
    "G", "g", 
    "H", "h", 
    "I", "i", 
    "J", "j", 
    "K", "k", 
    "L", "l", 
    "M", "m", 
    "N", "n", 
    "O", "o", 
    "P", "p", 
    "Q", "q", 
    "R", "r",
    "S", "s", 
    "T", "t", 
    "U", "u", 
    "V", "v", 
    "W", "w", 
    "X", "x", 
    "Y", "y", 
    "Z", "z"
]

g_node_names = [
    specific_device_name + "1",
    specific_device_name + "2",
    specific_device_name + "3",
    specific_device_name + "4",
    specific_device_name + "5",
    specific_device_name + "6"
]


def gen_random_device_names(node_names):
    device_count = 30
    # gen  device_count device names
    for _ in range(device_count):
        new_name = ""
        # gen unique device name
        while(True):
            new_name = ""
            name_length = 4
            # gen specific device
            if random.randint(0, 4) == 0:
                new_name = specific_device_name
            # add random letters
            alph_index = random.randint(0, len(alphabet) - 1)
            new_name = new_name + alphabet[alph_index]
            for _ in range(name_length - 1):
                if random.randint(0, 1) == 1:
                    alph_index = random.randint(0, len(alphabet) - 1)
                    new_name = new_name + alphabet[alph_index]
            if garbage_symbol in new_name:
                continue
            if node_names.count(new_name) == 0:
                break
        node_names.append(new_name)
        

def gen_new_file(node_names, dir, minute, is_empty=False):

    tmp_node_names = node_names.copy()
    # add garbage
    garbage_count = random.randint(0, 6)
    for _ in range(garbage_count):
        trash_values = []
        for _ in range(2):
            trash_values.append(str(random.getrandbits(random.randint(1,15))))
        garbage = trash_values[0] + garbage_symbol + trash_values[1]
        tmp_node_names.append(garbage)

    # add empty rows
    if is_empty:
        empty_count = random.randint(1, 5)
        for _ in range(empty_count):
            tmp_node_names.append(None)
 
    filename = "log_(" + datetime.datetime.now().strftime("%Y-%m-%d %H-") + str(minute) + ").txt"

    with open(dir + filename ,"w", encoding="utf-8") as ff:
        second = 0
        while len(tmp_node_names) != 0:
            elem_index = random.randint(0, len(tmp_node_names) - 1)
            elem = tmp_node_names[elem_index]
            del(tmp_node_names[elem_index])
            printed_row = ""
            if elem is not None:
                printed_row = str(second) + ":" + elem + ":" + str(random.getrandbits(10))
                if second < 59:
                    if random.randint(0, 3) == 0:
                        second  = second + random.randint(0, 1)
            ff.write(printed_row + "\n")


start = 11
end = 22


def is_empty_minute(minute, start, end):
    for _ in range(5):
        if minute == random.randint(start, end):
            return True
    return False

gen_random_device_names(g_node_names)

try:
    shutil.rmtree("logs")
except Exception as ex:
    print(ex)

try:
    os.mkdir("logs")
except Exception as ex:
    print(ex)

for minute in range(start, end):
    is_empty = is_empty_minute(minute, start, end)
    gen_new_file(g_node_names, "logs/", minute, is_empty) 
