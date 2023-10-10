```javascript
const fs = require('fs');

// Update README.md
const readmeContent = `
# Sample React Readme

This is a sample readme file for a React project.
`;

fs.writeFile('README.md', readmeContent, (error) => {
  if (error) {
    throw error;
  } else {
    // Read the updated README.md file
    fs.readFile('README.md', 'utf8', (error, data) => {
      if (error) {
        throw error;
      } else {
        console.log(data);
      }
    });
  }
});
```