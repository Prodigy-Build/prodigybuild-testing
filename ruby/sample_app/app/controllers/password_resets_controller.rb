require 'test_helper'

class PasswordResetsControllerTest < ActionDispatch::IntegrationTest
  def setup
    @user = users(:michael)
  end
  
  test "should get new" do
    get new_password_reset_path
    assert_response :success
  end

  test "should get new, with non-existing email" do
    post password_resets_path, params: { password_reset: { email: "" } }
    assert_not flash.empty?
    assert_redirected_to new_password_reset_url
  end
  
  test "should get valid user with active account" do
    post password_resets_path, params: { password_reset: { email: @user.email } }
    assert_not_equal @user.reset_digest, @user.reload.reset_digest
    assert_not flash.empty?
    assert_redirected_to root_url
  end

  test "get edit password reset form" do
    get edit_password_reset_path(@user.reset_token, email: "")
    assert_redirected_to root_url
    
    user.toggle!(:activated)
    get edit_password_reset_path(@user.reset_token, email: @user.email)
    assert_redirected_to root_url
    
    user.toggle!(:activated)
    get edit_password_reset_path('wrong token', email: @user.email)
    assert_redirected_to root_url
    
    get edit_password_reset_path(@user.reset_token, email: @user.email)
    assert_template 'password_resets/edit'
    assert_select "input[name=email][type=hidden][value=?]", user.email
  end

  test "invalid password & confirmation input" do
    patch password_reset_path(@user.reset_token), params: { email: @user.email, user: { password:              "foobaz", password_confirmation: "barquux" } }
    assert_select 'div#error_explanation'
  end

  test "empty password input" do
    patch password_reset_path(@user.reset_token), params: { email: @user.email, user: { password:              "", password_confirmation: "" } }
    assert_select 'div#error_explanation'
  end
  
  test "valid password & confirmation" do
    patch password_reset_path(@user.reset_token), params: { email: @user.email, user: { password:              "foobaz", password_confirmation: "foobaz" } }
    assert is_logged_in?
    assert_not flash.empty?
    assert_redirected_to @user
  end
end