

# users_helper_test.rb
require 'test_helper'

class UsersHelperTest < ActionView::TestCase

  test "gravatar_for should return an image tag" do
    user = User.new(name: "Example User", email: "user@example.com")
    assert_match /<img/, gravatar_for(user)
  end

  test "gravatar_for should accept size argument" do
    user = User.new(name: "Example User", email: "user@example.com")
    assert_match /s=50/, gravatar_for(user, size: 50)
  end

end