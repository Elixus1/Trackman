import matplotlib.pyplot as plt
import re

# Read and parse the content from the provided file
file_path = "trajectory.txt"
with open(file_path, 'r') as file:
    content = file.read()

# Extract x, y, z values using regular expressions
pattern = re.compile(r'\d+ \d+ \d+ ([\d\.\-eE]+) ([\d\.\-eE]+) ([\d\.\-eE]+)')
matches = pattern.findall(content)

# Convert matched strings to floats and split into x, y, z lists
x_vals = [float(match[0]) for match in matches]
y_vals = [float(match[1]) for match in matches]
z_vals = [float(match[2]) for match in matches]

# Create a 3D scatter plot
fig = plt.figure(figsize=(10, 7))
ax = fig.add_subplot(111, projection='3d')
ax.scatter(x_vals, y_vals, z_vals, c='blue', marker='o')

# Set labels and title
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('3D Scatter Plot of Atom Positions')

plt.tight_layout()
plt.savefig("trajectory.png")

