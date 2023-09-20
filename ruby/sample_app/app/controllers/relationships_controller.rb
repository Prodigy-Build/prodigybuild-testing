require 'test_helper'

class RelationshipsControllerTest < ActionController::TestCase
  def setup
    @user = users(:one)
    @other_user = users(:two)
  end

  test "should redirect create when not logged in" do
    assert_no_difference 'Relationship.count' do
      post :create
    end
    assert_redirected_to login_url
  end

  test "should redirect destroy when not logged in" do
    assert_no_difference 'Relationship.count' do
      delete :destroy, id: @user.relationships.first
    end
    assert_redirected_to login_url
  end

  test "should follow a user with Ajax" do
    assert_difference '@user.following.count', 1 do
      xhr :post, :create, followed_id: @other_user.id
    end
  end

  test "should unfollow a user with Ajax" do
    @user.follow(@other_user)
    relationship = @user.active_relationships.find_by(followed_id: @other_user.id)
    assert_difference '@user.following.count', -1 do
      xhr :delete, :destroy, id: relationship.id
    end
  end
end