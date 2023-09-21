```ruby
class SessionsController < ApplicationController
  before_action :downcase_email, only: :create
  before_action :find_user, only: :create

  def new
  end

  def create
    if @user && @user.authenticate(params[:session][:password])
      user_authenticated
    else
      flash.now[:danger] = 'Invalid email/password combination'
      render 'new'
    end
  end

  def destroy
    log_out if logged_in?
    redirect_to root_url
  end

  private

  def downcase_email
    params[:session][:email].downcase!
  end

  def find_user
    @user = User.find_by(email: params[:session][:email])
  end

  def user_authenticated
    if @user.activated?
      log_in @user
      params[:session][:remember_me] == '1' ? remember(@user) : forget(@user)
      redirect_back_or @user
    else
      flash[:warning] = "Account not activated. Check your email for the activation link."
      redirect_to root_url
    end
  end

  rescue_from ActiveRecord::RecordNotFound do
    flash.now[:danger] = 'Invalid email/password combination'
    render 'new'
  end
end
```
