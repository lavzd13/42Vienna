function daysBetween(date1, date2) {
	const timeDiff = Math.abs(date2.getTime() - date1.getTime());
	const daysDiff = Math.ceil(timeDiff / (1000 * 3600 * 24));
	return daysDiff;
}

document.addEventListener("DOMContentLoaded", () => {
	const dateInput = document.getElementById("date_input");
	const daysInput = document.getElementById("days_input");
	const circleInput = document.getElementById("circle_value");
	const submitButton = document.getElementById("submit");

	submitButton.addEventListener("click", () => {
	const date = dateInput.value;
	const days = daysInput.value;
	const circle = circleInput.value;

	if (!date) {
		alert("Fill out the page field");
		return;
	}

	const deadLines = [45, 118, 178, 306, 447, 644, 730]
	let blackHole = deadLines[circle] + Number(days);
	let currentDate = new Date();
	let daysLeft = blackHole - Number(daysBetween(currentDate, new Date(date)));
	if (Number.isNaN(daysLeft) || daysLeft < 0)
		daysLeft = 0;
	document.getElementById("result").innerText = `You have ${daysLeft} days left until your black hole.`;
	});

	daysInput.addEventListener("input", () => {
	if (daysInput.value > 180) daysInput.value = 180;
	if (daysInput.value < 0) daysInput.value = 0;
	});
});
