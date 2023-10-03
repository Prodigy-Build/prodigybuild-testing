class StaticPagesController < ApplicationController

  def home
    if logged_in?
      @micropost  = current_user.microposts.build
      @feed_items = current_user.feed.paginate(page: params[:page])
    end
  end

  def help
  end

  def about
  end

  def contact
  end
  
  def test_home
  end
  
  def test_help
  end
  
  def test_about
  end
  
  def test_contact
  end
end