import React from 'react';
import { render, fireEvent } from '@testing-library/react';
import Index from './index';

describe('Index Component', () => {
  it('renders without crashing', () => {
    render(<Index />);
  });

  it('updates state when input value is changed', () => {
    const { getByTestId } = render(<Index />);
    const input = getByTestId('input');
    fireEvent.change(input, { target: { value: 'New value' } });
    expect(input.value).toBe('New value');
  });
});