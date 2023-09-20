```ruby
class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception
  include SessionsHelper

  private

  def logged_in_user
    unless logged_in?
      store_location
      flash[:danger] = "Please log in."
      redirect_to login_url
    end
  end
end

# Adding below the unit test for the ApplicationController

require 'test_helper'

class ApplicationControllerTest < ActionDispatch::IntegrationTest

  test "should get danger flash when not logged in" do
    get root_url
    assert_redirected_to login_url
    assert_not flash[:danger].empty?
  end

  test "should store location when not logged in" do
    get root_url
    follow_redirect!
    assert_equal 'Please log in.', flash[:danger]
  end
end
```
