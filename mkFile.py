import os

# UTF-8 でテンプレートを読み込む
with open("ex.cpp", "r", encoding="utf-8") as tf:
    base_template = tf.read()

number = 420

folder_name = f"ABC{number}"
os.makedirs(folder_name, exist_ok=True)

for problem in "abcdefg":
    file_path = os.path.join(folder_name, f"{problem}.cpp")
    template = base_template.replace("{number}", str(number)).replace("{problem}", problem)
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(template)