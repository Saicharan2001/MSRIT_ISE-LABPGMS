<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>

	<h1>Patient Form</h1>

	<form action="Insert" method="get">
		<label>Name : </label> <input type="text" name="name" /> <label>ID
			: </label> <input type="number" name="id" />
		<button type="submit">Add Patient</button>
	</form>
	
	<br>

	<form action="Delete" method="get">
		<label>ID : </label> <input type="number" name="id" />
		<button type="submit">Delete Patient</button>
	</form>
	
	<br>

	<form action="Update" method="get">
		<label>Enter Existing ID : </label> <input type="number" name="id" /> <label>Enter new Name
			: </label> <input type="text" name="name" />
		<button type="submit">Update Patient</button>
	</form>
	
	<br>

	<form action="View">
		<button type="submit">View All Patients</button>
	</form>

</body>
</html>
