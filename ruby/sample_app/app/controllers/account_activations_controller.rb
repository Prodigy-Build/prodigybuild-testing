class AccountActivationsController < ApplicationController
  before_action :find_user, only: :edit

  def edit
    if @user && !@user.activated? && @user.authenticated?(:activation, params[:id])
      activate_user
    else
      flash[:danger] = "Invalid activation link"
      redirect_to root_url
    end
  rescue ActiveRecord::RecordNotFound
    flash[:danger] = "User not found"
    redirect_to root_url
  end

  private

  def find_user
    @user = User.find_by!(email: params[:email])
  end

  def activate_user
    @user.activate
    log_in @user
    flash[:success] = "Account activated!"
    redirect_to @user
  end
end