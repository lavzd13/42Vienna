from datetime import datetime, timedelta

circle_values = [45, 118, 178, 306, 447, 644, 730]

# Start date prompt
while True:
	input_str = input("Please provide the start date of your curriculum in this format(DD-MM-YYYY): ")
	try:
		start_date = datetime.strptime(input_str, "%d-%m-%Y")
		break
	except ValueError:
		print("Please provide valid date in this format DD-MM-YYYY")

# Circle number prompt
circle = 0
while True:
	circle = input("Please enter the number of your current circle (0-6): ")
	if circle.isdigit() and 0 <= int(circle) <= 6:
		circle = int(circle)
		break
	else:
		print("Please enter a valid integer from 0 to 6")

# Freeze and bonus days prompt
while True:
	freeze_days = input("Did you use any of your freeze or bonus days? y/n: ")
	if freeze_days == "y" or freeze_days == "n":
		break

# Freeze and bonus days number prompt
bonus_days = 0;
if freeze_days == "y":
	while True:
		bonus_days = input("Please provide the number of days that you used (freeze and bonus combined): ")
		if bonus_days.isdigit():
			bonus_days = int(bonus_days)
			break
		else:
			print("Please enter a valid integer")

# How many days are left to black hole (Bonus/Freeze days included)
black_hole = circle_values[circle] + bonus_days

current_date = datetime.now()
# How many days past from start of studies
duration_of_studies = current_date - start_date
# How many days are left until ultimate deadline
days_left = black_hole - duration_of_studies.days
# Date of the ultimate deadline
black_hole_date = current_date + timedelta(days=days_left)
print(f"\033[93m\nYou will be consumed by black hole on: {black_hole_date.strftime("%d-%m-%Y")}\nYou have {days_left} days left until black hole.\033[0m")
