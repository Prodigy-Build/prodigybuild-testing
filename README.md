```markdown
# prodigybuild-testing 

This repository contains the code and configurations for running tests and generating SLSA provenance files.

## Getting Started

### Prerequisites

For setting up this project, you will need to install:

- Python 3.9/3.10/3.11
- pip
- flake8
- pytest
- git

For **Windows/Mac OS** the above softwares can be installed using the following commands:

- Install Python

    - On **Mac OS** use `brew install python@3.9`, `brew install python@3.10` or `brew install python@3.11`.
    - On **Windows** download the executables from [https://www.python.org/downloads/windows/](https://www.python.org/downloads/windows/).

- Install pip: `python get-pip.py` 
- Install flake8: `pip install flake8`
- Install pytest: `pip install pytest`
- Install git: [https://git-scm.com/](https://git-scm.com/download)

### Installing

1. Clone the Repository: `git clone https://github.com/username/repo-name.git`
2. Move to the Directory: `cd repo-name`
3. Install dependencies: `pip install -r requirements.txt`

### Running the application locally 

From the root directory you can run `pytest` to start the application locally.

## Repository Environments

- The `main` branch is the production branch.
- The `github/workflows` directory contains all GitHub actions for CI/CD pipelines.

## Deployment

GitHub Actions are automatically triggered on push and pull requests to the `main` branch. Here are the workflows:

1. `datadog-synthetics.yml` for triggering Datadog Synthetic tests.
2. `generator-generic-ossf-slsa3-publish.yml` for generating SLSA provenance file.
3. `python-package.yml` for building and testing python packages.

Setting up GitHub actions requires adding the Datadog API (DD_API_KEY) and Application Key (DD_APP_KEY) as secrets to your GitHub repository. Refer to https://docs.datadoghq.com/account_management/api-app-keys/ for more information.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
```
