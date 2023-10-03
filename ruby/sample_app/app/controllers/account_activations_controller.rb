```ruby
require 'test_helper'

class AccountActivationsControllerTest < ActionDispatch::IntegrationTest
  test "should redirect to user if activation is successful" do
    user = users(:one)
    user.activation_token = User.new_token
    get edit_account_activation_url(user.activation_token, email: user.email)
    assert user.reload.activated?
    assert_redirected_to user_url(user)
  end

  test "should redirect to root if activation fails" do
    user = users(:one)
    user.activation_token = User.new_token
    get edit_account_activation_url('invalid_token', email: user.email)
    assert_not user.reload.activated?
    assert_redirected_to root_url
  end

  test "should set flash success message if activation is successful" do
    user = users(:one)
    user.activation_token = User.new_token
    get edit_account_activation_url(user.activation_token, email: user.email)
    assert_equal "Account activated!", flash[:success]
  end

  test "should set flash danger message if activation fails" do
    user = users(:one)
    user.activation_token = User.new_token
    get edit_account_activation_url('invalid_token', email: user.email)
    assert_equal "Invalid activation link", flash[:danger]
  end
end
```