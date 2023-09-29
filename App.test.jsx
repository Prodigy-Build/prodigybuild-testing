import React from 'react';
import { render, screen } from '@testing-library/react';
import userEvent from '@testing-library/user-event';
import App from './App';

test('renders learn react link', () => {
  render(<App />);
  const linkElement = screen.getByText(/learn react/i);
  expect(linkElement).toBeInTheDocument();
});

test('renders login button', () => {
  render(<App />);
  const loginButton = screen.getByRole('button', { name: /login/i });
  expect(loginButton).toBeInTheDocument();
});

test('clicking login button shows login form', () => {
  render(<App />);
  const loginButton = screen.getByRole('button', { name: /login/i });

  userEvent.click(loginButton);

  const loginForm = screen.getByLabelText(/username/i);
  expect(loginForm).toBeInTheDocument();
});

test('logging in with correct credentials changes user status to "Logged in"', () => {
  render(<App />);
  const loginButton = screen.getByRole('button', { name: /login/i });

  userEvent.click(loginButton);

  const usernameInput = screen.getByLabelText(/username/i);
  const passwordInput = screen.getByLabelText(/password/i);
  const submitButton = screen.getByRole('button', { name: /submit/i });

  userEvent.type(usernameInput, 'testuser');
  userEvent.type(passwordInput, 'testpassword');
  userEvent.click(submitButton);

  const userStatus = screen.getByText(/Logged in/i);
  expect(userStatus).toBeInTheDocument();
});

test('logging in with incorrect credentials does not change user status', () => {
  render(<App />);
  const loginButton = screen.getByRole('button', { name: /login/i });

  userEvent.click(loginButton);

  const usernameInput = screen.getByLabelText(/username/i);
  const passwordInput = screen.getByLabelText(/password/i);
  const submitButton = screen.getByRole('button', { name: /submit/i });

  userEvent.type(usernameInput, 'testuser');
  userEvent.type(passwordInput, 'wrongpassword');
  userEvent.click(submitButton);

  const userStatus = screen.queryByText(/Logged in/i);
  expect(userStatus).not.toBeInTheDocument();
});