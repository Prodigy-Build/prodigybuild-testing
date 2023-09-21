```ruby
class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception
  include SessionsHelper

  private

    # Confirms a logged-in user.
    def logged_in_user
      if logged_in?
        yield
      else
        handle_not_logged_in
      end
    rescue
      handle_error
    end

    def handle_not_logged_in
      store_location
      flash[:danger] = "Please log in."
      redirect_to login_url
    end

    def handle_error
      flash[:error] = "An error occurred."
      redirect_to root_url
    end

end
```