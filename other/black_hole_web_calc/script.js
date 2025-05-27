// Function to calculate the diff in days between two dates
function daysBetween(date1, date2) {
	const timeDiff = Math.abs(date2.getTime() - date1.getTime());
	const daysDiff = Math.ceil(timeDiff / (1000 * 3600 * 24));
	return daysDiff;
}

document.addEventListener("DOMContentLoaded", () => {
	// Getting the inputs from the html elements
	const dateInput = document.getElementById("date_input");
	const daysInput = document.getElementById("days_input");
	const circleInput = document.getElementById("circle_value");
	const submitButton = document.getElementById("submit");

	// Waiting for the button click
	submitButton.addEventListener("click", () => {
	// Getting the values from input fields
	const date = dateInput.value;
	const days = daysInput.value;
	const circle = circleInput.value;

	// Checking if date is entered
	if (!date) {
		alert("Fill out the date field");
		return;
	}
	// Circle deadlines in days for 42Vienna, maybe it can differ from campus to campus
	const deadLines = [45, 118, 178, 306, 447, 644, 730]

	// Adding the freeze/bonus days, if some are used
	let blackHole = deadLines[circle] + Number(days);
	const currentDate = new Date();

	// Calculating how many days are left until ultimate deadline
	let daysLeft = blackHole - Number(daysBetween(currentDate, new Date(date)));

	// Just to make prettier output on web page
	if (Number.isNaN(daysLeft) || daysLeft < 0)
		daysLeft = 0;

	// Adding days to current date so that we can print out also the date of the black hole
	const blackDate = new Date();
	blackDate.setDate(currentDate.getDate() + daysLeft);

	// Printing out the result
	document.getElementById("result").innerText = `You have ${daysLeft} days left until your black hole.`;
	document.getElementById("result_date").innerText = `Your black hole will be on: ${blackDate.toDateString()}`;
	});

	// Limiting the user input for freeze/bonus days
	daysInput.addEventListener("input", () => {
	if (daysInput.value > 180) daysInput.value = 180;
	if (daysInput.value < 0) daysInput.value = 0;
	});
});
