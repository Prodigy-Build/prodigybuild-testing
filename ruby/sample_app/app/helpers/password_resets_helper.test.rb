


# PasswordResetsHelperTest

require 'test_helper'

class PasswordResetsHelperTest < ActionView::TestCase
  test "should generate reset token" do
    token = PasswordResetsHelper.generate_token
    assert_not_nil token
  end

  test "should generate reset digest" do
    digest = PasswordResetsHelper.generate_digest('test')
    assert_not_nil digest
  end
end