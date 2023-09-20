require 'test_helper'

class SessionsControllerTest < ActionDispatch::IntegrationTest

  def setup
    @user = users(:michael)
  end

  test "should get new" do
    get login_path
    assert_response :success
  end

  test "should login with valid email/password" do
    post login_path, params: { session: { email: @user.email, password: 'password' } }
    assert_redirected_to @user
    assert is_logged_in?
  end

  test "should not login with invalid email/password" do
    post login_path, params: { session: { email: "wrong", password: "wrong" } }
    assert_template 'sessions/new'
    assert_not flash.empty?
    assert_not is_logged_in?
  end

  test "should logout" do
    log_in_as(@user)
    delete logout_path
    assert_not is_logged_in?
    assert_redirected_to root_url
  end
end