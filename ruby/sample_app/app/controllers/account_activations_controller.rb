require 'test_helper'

class AccountActivationsControllerTest < ActionDispatch::IntegrationTest
  
  def setup
    @user = users(:unactivated)
  end

  test "should activate user" do
    get edit_account_activation_path(@user.activation_token, email: @user.email)
    assert @user.reload.activated?
  end

  test "should not activate user with wrong token" do
    get edit_account_activation_path("wrong token", email: @user.email)
    assert_not @user.reload.activated?
  end
  
  test "should not activate user with wrong email" do
    get edit_account_activation_path(@user.activation_token, email: "wrong")
    assert_not @user.reload.activated?
  end
  
end