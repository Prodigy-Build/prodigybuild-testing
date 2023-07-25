

# ruby/sample_app/app/helpers/static_pages_helper.test.rb

require 'test_helper'

class StaticPagesHelperTest < ActionView::TestCase
  test "should return the correct title for the home page" do
    assert_equal "Home | Sample App", full_title("Home")
  end

  test "should return the correct title for the about page" do
    assert_equal "About | Sample App", full_title("About")
  end

  test "should return the correct title for the contact page" do
    assert_equal "Contact | Sample App", full_title("Contact")
  end
end