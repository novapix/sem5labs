# HTML Tables and Forms Example


### Table Elements:
1. **`<table>`**: Defines the table structure.
   - `border="1"`: Adds a border to the table for visibility.

2. **`<caption>`**: Provides a caption for the table.
   - **Text**: "Employee details" - Description of the table content.

3. **`<thead>`**: Defines the header section of the table.
   - Contains the header row with `<th>` elements.

4. **`<tbody>`**: Defines the body section of the table.
   - Contains the actual rows of data.

5. **`<tr>`**: Represents a table row.
   - Used for grouping each row of data in the table.

6. **`<th>`**: Represents a table header cell.
   - Contains column headers such as "Name", "Position", "Office", and "Age".

7. **`<td>`**: Represents a table data cell.
   - Displays employee data such as name, position, office location, and age.

8. **`rowspan`**: Used in the `<td>` element to merge two rows into one.
   - Applied to the name column for employees holding multiple positions.

9. **`colspan`**: Used in the `<td>` element to merge multiple columns into one.
   - Used to display the total number of employees across multiple columns.

### Form Elements:
1. **`<form>`**: Defines the form element.
   - `action="/submit-form"`: Specifies the URL where the form data will be submitted.
   - `method="post"`: Specifies that the form will use the POST method to send data.

2. **`<label>`**: Defines a label for form inputs.
   - **`for="name"`**: Links the label to the corresponding input element with the ID "name".

3. **`<input>`**: Defines an input field.
   - `type="text"`: For text input (e.g., Full Name).
   - `type="email"`: For email input (e.g., Email Address).
   - `type="radio"`: For selecting one of the gender options (Male/Female).
   - `type="date"`: For selecting a date (e.g., Date of Birth).
   - `type="number"`: For entering numeric values (e.g., Years of Experience).
   - `type="tel"`: For entering a telephone number.
   - `type="url"`: For entering a URL (e.g., LinkedIn Profile).
   - `type="checkbox"`: Defines checkboxes for selecting multiple skills.

4. **`<textarea>`**: Defines a multiline text input.
   - `rows="4"` and `cols="50"`: Specifies the visible size of the textarea (4 rows and 50 columns).

5. **`<select>`**: Defines a dropdown list.
   - Contains `<option>` elements for selecting one of the predefined positions.

6. **`<option>`**: Defines an option in a `<select>` dropdown list.
   - Contains various position options like "Developer", "Manager", etc.


7. **`<input type="submit">`**: Defines a submit button for the form.
   - Used to submit the form data to the specified action URL.

### Additional Attributes:
- **`required`**: Specifies that a form field is required to be filled out before submitting the form.
- **`min`** and **`max`**: Defines the range of acceptable values for a number input (e.g., Years of Experience).
- **`pattern`**: Specifies a regular expression pattern to validate the input (e.g., for telephone number validation).
- **`placeholder`**: Provides a placeholder text inside an input field (not used in the current code but can be added).



