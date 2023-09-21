class StaticPagesController < ApplicationController

  def home
    if logged_in?
      @micropost  = current_user.microposts.build
      @feed_items = current_user.feed.paginate(page: params[:page])
    end
  rescue
    render 'errors/standard_error'
  end

  def help
  rescue
    render 'errors/standard_error'
  end
  
  def about
  rescue
    render 'errors/standard_error'
  end

  def contact
  rescue
    render 'errors/standard_error'
  end
end