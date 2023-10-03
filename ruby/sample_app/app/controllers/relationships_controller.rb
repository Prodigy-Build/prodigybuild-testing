require 'test_helper'

class RelationshipsControllerTest < ActionController::TestCase
  def setup
    @user = users(:michael)
    @other_user = users(:archer)
    log_in_as(@user)
  end

  test "should create relationship" do
    assert_difference '@user.following.count', 1 do
      post :create, params: { followed_id: @other_user.id }
    end
  end

  test "should destroy relationship" do
    @user.follow(@other_user)
    relationship = @user.active_relationships.find_by(followed_id: @other_user.id)
    assert_difference '@user.following.count', -1 do
      delete :destroy, params: { id: relationship.id }
    end
  end
end