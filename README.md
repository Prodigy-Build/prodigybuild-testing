```jsx
const fs = require('fs');

const updateFile = (filename, content) => {
  fs.writeFileSync(filename, content);
  return fs.readFileSync(filename, 'utf8');
};

const updateReadme = () => {
  const readmeContent = 'Write a sample react readme.';
  return updateFile('README.md', readmeContent);
};

updateReadme();
```