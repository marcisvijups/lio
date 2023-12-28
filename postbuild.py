import sys

def parse_source(filepath):
	# Open the file and read the contents
	with open(filepath, "r") as f:
		contents = f.read()
	# Split the contents by newlines
	lines = contents.split("\n")
	task_id = filepath.split("_")[-1]
	task_id = task_id.split("/")[0]
	print(" task id :", task_id)

	for line in lines:
		if line.count(task_id+".rez") > 0 or line.count(task_id+".out") > 0:
			return(line)

def main():
	if len(sys.argv) > 1:
		filepath = sys.argv[1]
		print("\n")
		print("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
		print("\n")
		print(f"**** POSTBUILD RAN WITH : {filepath} ****")
		# Add your post-build logic here using the filepath
		return parse_source(filepath)
	else:
		print("POSTBUILD RAN WITHOUT ARGS")
		return 0

	print("\n")
	print("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")
	print("\n")




if __name__ == "__main__":
	main()
